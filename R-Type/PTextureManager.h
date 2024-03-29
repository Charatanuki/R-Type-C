#pragma once

extern SDL_Texture* playerTextureNormal;
extern SDL_Texture* playerTextureInvincible;


void freePlayerTextures();
int loadPlayerTextures(SDL_Renderer* renderer);
SDL_Texture* loadPlayerTexture(SDL_Renderer* renderer, int type);