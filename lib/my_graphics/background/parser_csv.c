/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that parse a csv file into an int table
*/
#include "../include/background.h"

static char * get_file(char const * path)
{
    struct stat data;
    memset(&data, 0, sizeof(struct stat));
    stat(path, &data);
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        write(2, "unable to open \"", 16);
        write(2, path, mystrlen(path));
        write(2, "\"\n", 2);
        return NULL;
    }
    char * buffer = malloc(data.st_size + 1);
    memset(buffer, 0, data.st_size + 1);
    ssize_t bytes_read = read(fd, buffer, data.st_size);
    close(fd);
    if (bytes_read != data.st_size) {
        write(2, "failed to read entire file\n", 26);
        free(buffer);
        return NULL;
    }
    return buffer;
}

static void get_dimension(char const * buffer, int * width, int * height)
{
    if (buffer == NULL) {
        return;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ',' && *height == 0) {
            *width += 1;
        }
        if (buffer[i] == '\n') {
            *height += 1;
        }
    }
    *width += 1;
}

static int ** fill_file(char const * buffer, int width, int height)
{
    int x = -1;
    int y = 0;
    int ** file = malloc(sizeof(int *) * (height + 1));
    file[height] = NULL;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (x == -1 && y < height) {
            file[y] = malloc(sizeof(int) * (width + 1));
            file[y][0] = 0;
            file[y][width] = -2;
            x = 0;
        }
        switch (buffer[i]) {
            case '\n': x = -1; y++; continue; break;
            case ',': x++; file[y][x] = 0; continue; break;
            case '-': file[y][x] = -1; i++; break;
            default: file[y][x] *= 10; file[y][x] += buffer[i] - '0'; break;
        }
    }
    return file;
}

int ** parser_csv(char const * path)
{
    int width = 0;
    int height = 0;
    int ** file = NULL;
    char * buffer = get_file(path);
    if (buffer == NULL) {
        write(2, "abort parsing\n", 14);
        return NULL;
    }
    get_dimension(buffer, &width, &height);
    file = fill_file(buffer, width, height);
    free(buffer);
    return file;
}
