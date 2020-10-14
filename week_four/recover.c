#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Program takes a .raw file and recovers images from it

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    // If exactly one command line arg not present, return 1 and usage message
    if (argc != 2)
    {
        printf("This program requires one command line argument");
        return 1;
    }
    // open memory card in "r"/read mode
    FILE *file = fopen(argv[1], "r");
    // If forensic image can't be opened for reading, return 1 and inform user
    if (file == NULL)
    {
        printf("Forensic image cannot be opened for reading");
        return 1;
    }

    // set block size and temp storage
    int BLOCK = 512;
    BYTE buffer[BLOCK];
    FILE *img;

    // counter for unique file name
    int file_counter = 0;

    // tracker for if jpeg file is currently open, 1 == false / 0 == true
    int open_file = 1;

    // While not at end of file - read 512 bytes in file and store in buffer
    while (fread(buffer, BLOCK, 1, file) == 1)
    {
        // Check if you're at beginning of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not the first jpeg, close file and increase counter
            if (open_file == 0)
            {
                fclose(img);
                file_counter++;
            }
            else
            {
                // If this is the first jpeg file, set file_open to true
                open_file = 0;
            }

            //Create a new jpeg file to put your image information into
            char image_file[BLOCK];
            sprintf(image_file, "%03i.jpg", file_counter);
            img = fopen(image_file, "w");
            fwrite(buffer, BLOCK, 1, img);

            // not the start of a first jpeg
        }
        else
        {
            // If jpeg file is currently open, add additional bytes to file
            if (open_file == 0)
            {
                fwrite(buffer, BLOCK, 1, img);
            }
        }
    }

    return 0;
}
