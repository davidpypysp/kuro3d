#include <iostream>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>

#include "src/core/renderer/model_loader.h"
#include "src/core/engine.h"

namespace kuro {

std::vector<std::shared_ptr<Texture>> LoadMaterialTextures(
    aiMaterial *mat, const std::string &directory, const aiTextureType &type,
    const TextureType &texture_type) {
  std::vector<std::shared_ptr<Texture>> textures;
  for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
    aiString str;
    mat->GetTexture(type, i, &str);
    std::string path = directory + "/" + std::string(str.C_Str());
    auto texture = Engine::GetTextureLoader()->LoadTexture(path, texture_type);
    textures.push_back(texture);
  }
  return textures;
}

Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene,
                 const std::string &directory) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;

  for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
    Vertex vertex;
    vec3 vector;
    vector.x = mesh->mVertices[i].x;
    vector.y = mesh->mVertices[i].y;
    vector.z = mesh->mVertices[i].z;
    vertex.position = vector;

    if (mesh->HasNormals()) {
      vector.x = mesh->mNormals[i].x;
      vector.y = mesh->mNormals[i].y;
      vector.z = mesh->mNormals[i].z;
      vertex.normal = vector;
    }
    if (mesh->mTextureCoords[0]) {
      vec2 vec;
      vec.x = mesh->mTextureCoords[0][i].x;
      vec.y = mesh->mTextureCoords[0][i].y;
      vertex.tex_coords = vec;

      vector.x = mesh->mTangents[i].x;
      vector.y = mesh->mTangents[i].y;
      vector.z = mesh->mTangents[i].z;
      vertex.tangent = vector;

      vector.x = mesh->mBitangents[i].x;
      vector.y = mesh->mBitangents[i].y;
      vector.z = mesh->mBitangents[i].z;
      vertex.bitangent = vector;
    } else {
      vertex.tex_coords = vec2(0.0f, 0.0f);
    }
    vertices.push_back(vertex);
  }

  for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
    aiFace face = mesh->mFaces[i];
    for (unsigned int j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  std::vector<std::shared_ptr<Texture>> textures;
  aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
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

  return Mesh(vertices, indices, textures);
}

void ProcessNode(aiNode *node, const aiScene *scene,
                 const std::string &directory, std::vector<Mesh> *meshes) {
  for (unsigned int i = 0; i < node->mNumMeshes; i++) {
    aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
    meshes->push_back(ProcessMesh(mesh, scene, directory));
  }
  for (unsigned int i = 0; i < node->mNumChildren; i++) {
    ProcessNode(node->mChildren[i], scene, directory, meshes);
  }
}

ModelLoader::ModelLoader() {}

void ModelLoader::LoadModel(const std::string &path,
                            std::vector<Mesh> *meshes) {
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile(
      path, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

  if (!scene || scene->mFlags && AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
  }
  std::string directory = path.substr(0, path.find_last_of('/'));
  ProcessNode(scene->mRootNode, scene, directory, meshes);
}

}  // namespace kuro