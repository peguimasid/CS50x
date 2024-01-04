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

// color: 0 -> red | 1 -> green | 2 -> blue
int getBlurColor(int y, int x, int h, int w, RGBTRIPLE copy[h][w], int color) {
  int counter = 0;
  int sum = 0;

  for (int i = y - 1; i <= (y + 1); i++) {
    for (int j = x - 1; j <= (x + 1); j++) {
      if (i < 0 || j < 0 || i >= h || j >= w) continue;
      if (color == 0) {
        sum += copy[i][j].rgbtRed;
      }
      if (color == 1) {
        sum += copy[i][j].rgbtGreen;
      }
      if (color == 2) {
        sum += copy[i][j].rgbtBlue;
      }
      counter++;
    }
  }

  return sum / counter;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j].rgbtRed = getBlurColor(i, j, height, width, copy, 0);
      image[i][j].rgbtGreen = getBlurColor(i, j, height, width, copy, 1);
      image[i][j].rgbtBlue = getBlurColor(i, j, height, width, copy, 2);
    }
  }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  return;
}
