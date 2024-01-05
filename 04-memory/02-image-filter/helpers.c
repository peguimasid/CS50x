#include "helpers.h"

#include <math.h>
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

// color: 0 -> red | 1 -> green | 2 -> blue
int getEdgeColor(int y, int x, int h, int w, RGBTRIPLE copy[h][w], int color) {
  int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
  int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

  int gx_color = 0;
  int gy_color = 0;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int rowIndex = y + i;
      int colIndex = x + j;

      if (rowIndex < 0 || rowIndex >= h || colIndex < 0 || colIndex >= w) {
        gx_color += 0;
        gy_color += 0;
        continue;
      }

      RGBTRIPLE current_pixel = copy[rowIndex][colIndex];

      if (color == 0) {
        gx_color += gx[i + 1][j + 1] * current_pixel.rgbtRed;
        gy_color += gy[i + 1][j + 1] * current_pixel.rgbtRed;
      }

      if (color == 1) {
        gx_color += gx[i + 1][j + 1] * current_pixel.rgbtGreen;
        gy_color += gy[i + 1][j + 1] * current_pixel.rgbtGreen;
      }

      if (color == 2) {
        gx_color += gx[i + 1][j + 1] * current_pixel.rgbtBlue;
        gy_color += gy[i + 1][j + 1] * current_pixel.rgbtBlue;
      }
    }
  }

  int result = sqrt((gx_color * gx_color) + (gy_color * gy_color));

  if (result > 255) {
    return 255;
  }

  return result;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j].rgbtRed = getEdgeColor(i, j, height, width, copy, 0);
      image[i][j].rgbtGreen = getEdgeColor(i, j, height, width, copy, 1);
      image[i][j].rgbtBlue = getEdgeColor(i, j, height, width, copy, 2);
    }
  }
}
