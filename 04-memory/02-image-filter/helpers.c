#include "helpers.h"

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
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  return;
}
