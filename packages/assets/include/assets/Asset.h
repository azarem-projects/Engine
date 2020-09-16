#pragma once

#include <map>
#include <vector>
#include <string>
#include <sstream>

namespace api
{
    namespace assets
    {
        enum AssetType
        {
            Undefined,
            Text,
            Model,
            Image
        };

        static std::map<AssetType, std::vector<std::string>> formats =
        {
            std::pair<AssetType, std::vector<std::string>> 
            {
                AssetType::Model, std::vector<std::string> 
                {
                    "fbx",
                    "obj"
                }
            },
            std::pair<AssetType, std::vector<std::string>> 
            {
                AssetType::Image, std::vector<std::string> 
                {
                    "png",
                    "jpg"
                }
            },
            std::pair<AssetType, std::vector<std::string>> 
            {
                AssetType::Text, std::vector<std::string> 
                {
                    "glsl",
                    "txt",
                    "json"
                }
            }
        };

        std::vector<std::string> split(const std::string& s, char delimiter);

        template <typename T>
        bool vectorContains(const std::vector<T>& vector, const T& item)
        {
            for (int i = 0; i < vector.size(); i++)
            {
                if (vector[i] == item)
                {
                    return true;
                }
            }

            return false;
        }

        AssetType getAssetType(const std::string& format);

        std::string getAssetFormat(const std::string& path);

        struct ModelAsset
        {
            std::vector<float> positions;
            std::vector<int> indices;
            std::vector<float> uvs;

            ModelAsset(const std::string& path);
        };

        struct ImageAsset
        {
            ImageAsset(const std::string& path);
        };

        struct TextAsset
        {
            std::string content;

            TextAsset(const std::string& path);
        };

        struct Asset
        {
            ModelAsset* model;
            ImageAsset* image;
            TextAsset* text;

            AssetType type;
        };

        Asset* import(const std::string& path);
    }
}
