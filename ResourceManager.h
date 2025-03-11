#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>

class TextureManager //I want to speak to your texture manager!
{
public:
    static TextureManager& GetInstance()
    {
        static TextureManager instance;
        return instance;
    }

    Texture2D GetTexture(const std::string& fileName)
    {
        if (textures.find(fileName) == textures.end())
        {
            textures[fileName] = LoadTexture(fileName.c_str());
            loadCount[fileName] = 1;
        }
        else
        {
            loadCount[fileName]++;
        }
        return textures[fileName];
    }

    void UnloadTexture(const std::string& fileName)
    {
        if (textures.find(fileName) != textures.end())
        {
            loadCount[fileName]--;

            if (loadCount[fileName] <= 0)
            {
                ::UnloadTexture(textures[fileName]);
                textures.erase(fileName);
                loadCount.erase(fileName);
            }
        }
    }

    ~TextureManager()
    {
        for (auto& pair : textures)
        {
            ::UnloadTexture(pair.second);
        }
        textures.clear();
        loadCount.clear();
    }

private:
    TextureManager() {};

    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, int> loadCount;

    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;
};


