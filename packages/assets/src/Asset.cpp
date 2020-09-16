#include "Asset.h"

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

// #include <debug/Log.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace api
{
    namespace assets
    {
        ModelAsset::ModelAsset(const std::string& path)
        {
            Assimp::Importer importer;

            const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);

            aiMesh* mesh = scene->mMeshes[0];

            for (int i = 0; i < mesh->mNumVertices; i++)
            {
                positions.emplace_back(mesh->mVertices[i].x);
                positions.emplace_back(mesh->mVertices[i].y);
                positions.emplace_back(mesh->mVertices[i].z);

                uvs.emplace_back(mesh->mTextureCoords[0][i].x);
                uvs.emplace_back(mesh->mTextureCoords[0][i].y);
            }

            for (int i = 0; i < mesh->mNumFaces; i++)
            {
                aiFace* face = &mesh->mFaces[i];
                indices.emplace_back(face->mIndices[0]);
                indices.emplace_back(face->mIndices[1]);
                indices.emplace_back(face->mIndices[2]);
            }
        }

        ImageAsset::ImageAsset(const std::string& path)
        {
            
        }

        TextAsset::TextAsset(const std::string& path)
        {
            std::ifstream fileStream(path, std::ios::in);

            if (!fileStream.is_open()) {
                std::cout << "Could not read file {0}. File does not exist.\n";
                // ENGINE_ERROR("Could not read file {0}. File does not exist.", path);
            }

            std::string line = "";
            while (!fileStream.eof()) {
                getline(fileStream, line);
                content.append(line + "\n");
            }

            fileStream.close();
        }

        std::vector<std::string> split(const std::string& s, char delimiter)
        {
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(s);

            while (std::getline(tokenStream, token, delimiter))
            {
                if (token.length() > 0)
                {
                    tokens.push_back(token);
                }
            }

            return tokens;
        }

        AssetType getAssetType(const std::string& format)
        {
            for (auto const& x : formats)
            {
                std::vector<std::string> y = x.second;

                if (vectorContains(y, format))
                {
                    return x.first;
                }
            }

            return AssetType::Undefined;
        }

        std::string getAssetFormat(const std::string& path)
        {
            std::vector<std::string> parts = split(path, '.');
            
            if (parts.size() < 2)
            {
                return "";
            }
            
            return parts[1];
        }

        Asset* import(const std::string& path)
        {
            Asset* asset = new Asset();

            std::string format = getAssetFormat(path);
            asset->type = getAssetType(format);

            if (asset->type == AssetType::Model)
            {
                asset->model = new ModelAsset(path);
            }

            if (asset->type == AssetType::Image)
            {
                asset->image = new ImageAsset(path);
            }

            if (asset->type == AssetType::Text)
            {
                asset->text = new TextAsset(path);
            }

            return asset;
        }
    }
}