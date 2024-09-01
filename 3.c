
#include <stdio.h>

void decimalToBinary(int n, FILE *destinationFile)
{
    if (n > 1)
        decimalToBinary(n / 2, destinationFile);

    fprintf(destinationFile, "%d", n % 2);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <source_file> <destination_file> <n>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destinationFile = fopen(argv[2], "w");
    int n = atoi(argv[3]);

    if (sourceFile == NULL || destinationFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    int decimalNumber;
    for (int i = 0; i < n; i++)
    {
        if (fscanf(sourceFile, "%d", &decimalNumber) == 1)
        {
            decimalToBinary(decimalNumber, destinationFile);

            fprintf(destinationFile, "\n");
            printf("The binary equivalent of %d is ", decimalNumber);
            fseek(destinationFile, -9, SEEK_CUR); 
            int binaryDigit;
            while (fscanf(destinationFile, "%1d", &binaryDigit) == 1)
            {
                printf("%d", binaryDigit);
            }
            printf("\n");
            fseek(destinationFile, 0, SEEK_END); 
        }
        else
        {
            printf("Error reading decimal numbers from the source file.\n");
            break;
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
