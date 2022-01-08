#include "src/core/loader/model_loader.h"

#include <iostream>

#include "src/core/base/geometry.h"
#include "src/core/base/mesh_basic_material.h"

namespace kuro {

ModelLoader::ModelLoader() {}

void ModelLoader::LoadModel(const std::string &path,
                            std::shared_ptr<SceneNode> scene_node) {
  Assimp::Importer importer;
  const aiScene *ai_scene = importer.ReadFile(
      path, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

  if (!ai_scene || ai_scene->mFlags && AI_SCENE_FLAGS_INCOMPLETE ||
      !ai_scene->mRootNode) {
    std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
  }
  std::string directory = path.substr(0, path.find_last_of('/'));
  ProcessNode(ai_scene->mRootNode, ai_scene, directory, scene_node);
}

std::vector<std::shared_ptr<Texture>> ModelLoader::LoadMaterialTextures(
    aiMaterial *ai_mat, const std::string &directory,
    const aiTextureType &ai_texture_type, const TextureType &texture_type) {
  std::vector<std::shared_ptr<Texture>> textures;
  for (unsigned int i = 0; i < ai_mat->GetTextureCount(ai_texture_type); i++) {
    aiString str;
    ai_mat->GetTexture(ai_texture_type, i, &str);
    std::string path = directory + "/" + std::string(str.C_Str());
    auto texture = texture_loader_->LoadTexture(path, texture_type);
    textures.push_back(texture);
  }
  return textures;
}

std::shared_ptr<MeshComp> ModelLoader::ProcessMesh(
    aiMesh *ai_mesh, const aiScene *ai_scene, const std::string &directory) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;

  for (unsigned int i = 0; i < ai_mesh->mNumVertices; i++) {
    Vertex vertex;
    vec3 vector;
    vector.x = ai_mesh->mVertices[i].x;
    vector.y = ai_mesh->mVertices[i].y;
    vector.z = ai_mesh->mVertices[i].z;
    vertex.position = vector;

    if (ai_mesh->HasNormals()) {
      vector.x = ai_mesh->mNormals[i].x;
      vector.y = ai_mesh->mNormals[i].y;
      vector.z = ai_mesh->mNormals[i].z;
      vertex.normal = vector;
    }
    if (ai_mesh->mTextureCoords[0]) {
      vec2 vec;
      vec.x = ai_mesh->mTextureCoords[0][i].x;
      vec.y = ai_mesh->mTextureCoords[0][i].y;
      vertex.tex_coords = vec;

      vector.x = ai_mesh->mTangents[i].x;
      vector.y = ai_mesh->mTangents[i].y;
      vector.z = ai_mesh->mTangents[i].z;
      vertex.tangent = vector;

      vector.x = ai_mesh->mBitangents[i].x;
      vector.y = ai_mesh->mBitangents[i].y;
      vector.z = ai_mesh->mBitangents[i].z;
      vertex.bitangent = vector;
    } else {
      vertex.tex_coords = vec2(0.0f, 0.0f);
    }
    vertices.push_back(vertex);
  }

  for (unsigned int i = 0; i < ai_mesh->mNumFaces; i++) {
    aiFace face = ai_mesh->mFaces[i];
    for (unsigned int j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  std::vector<std::shared_ptr<Texture>> textures;
  aiMaterial *material = ai_scene->mMaterials[ai_mesh->mMaterialIndex];
  auto diffuse_textures = LoadMaterialTextures(
      material, directory, aiTextureType_DIFFUSE, TextureType::DIFFUSE);
  textures.insert(textures.end(), diffuse_textures.begin(),
                  diffuse_textures.end());

  auto specular_textures = LoadMaterialTextures(
      material, directory, aiTextureType_SPECULAR, TextureType::SPECULAR);
  textures.insert(textures.end(), specular_textures.begin(),
                  specular_textures.end());

  auto normal_textures = LoadMaterialTextures(
      material, directory, aiTextureType_HEIGHT, TextureType::NORMAL);
  textures.insert(textures.end(), normal_textures.begin(),
                  normal_textures.end());

  auto height_textures = LoadMaterialTextures(
      material, directory, aiTextureType_AMBIENT, TextureType::HEIGHT);
  textures.insert(textures.end(), height_textures.begin(),
                  height_textures.end());

  auto geometry = std::make_shared<Geometry>(vertices, indices);
  auto mesh_basic_material = std::make_shared<MeshBasicMaterial>();
  if (diffuse_textures.size() > 0) {
    mesh_basic_material->diffuse_map = diffuse_textures[0];
  }
  if (specular_textures.size() > 0) {
    mesh_basic_material->specular_map = specular_textures[0];
  }
  if (normal_textures.size() > 0) {
    mesh_basic_material->normal_map = normal_textures[0];
  }
  if (height_textures.size() > 0) {
    mesh_basic_material->height_map = height_textures[0];
  }

  auto mesh_comp = std::make_shared<MeshComp>(geometry, mesh_basic_material);
  return mesh_comp;
}

void ModelLoader::ProcessNode(aiNode *ai_node, const aiScene *ai_scene,
                              const std::string &directory,
                              std::shared_ptr<SceneNode> scene_node) {
  for (unsigned int i = 0; i < ai_node->mNumMeshes; i++) {
    aiMesh *ai_mesh = ai_scene->mMeshes[ai_node->mMeshes[i]];
    auto mesh_comp = ProcessMesh(ai_mesh, ai_scene, directory);
    scene_node->BindComponent(mesh_comp);
  }
  for (unsigned int i = 0; i < ai_node->mNumChildren; i++) {
    aiNode *ai_child = ai_node->mChildren[i];
    const auto &node_name = std::string(ai_child->mName.C_Str());
    auto child_node = scene_manager_->CreateSceneNode(node_name, scene_node);
    ProcessNode(ai_child, ai_scene, directory, child_node);
  }
}

}  // namespace kuro