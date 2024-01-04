#include "helpers.h"

#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      BYTE red = image[y][x].rgbtRed;
      BYTE green = image[y][x].rgbtGreen;
      BYTE blue = image[y][x].rgbtBlue;

      BYTE average = (red + green + blue) / 3;

      image[y][x].rgbtRed = average;
      image[y][x].rgbtGreen = average;
      image[y][x].rgbtBlue = average;
    }
  }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      RGBTRIPLE tmp = image[y][x];
      image[y][x] = image[y][width - x];
      image[y][width - x] = tmp;
    }
  }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  return;
}
