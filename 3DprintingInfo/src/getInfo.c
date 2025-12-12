#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    ssize_t gcodeSize;
    struct stat gcodeFileSize;

    char * target;
    char material[16] = {0};
    char tempo[16] = {0};

    int gcodeFD;

    if ((argc == 2) && argv[1] != NULL)
    {
        gcodeFD = open(argv[1], O_RDONLY);
        if ((gcodeFD) != -1)
        {
            if (fstat(gcodeFD, &gcodeFileSize))
            {
                perror("fstat");
            }
            
            char * gcode = (char *)malloc(sizeof(char)*gcodeFileSize.st_size + 1);

            if (!(gcodeSize = read(gcodeFD, gcode, gcodeFileSize.st_size)))
            {
                perror("read");
                printf("O arquivo passado tem 0 caracteres.");
                return 0;
            }
            
            gcode[gcodeFileSize.st_size] = '\0';

            target = strstr(gcode, "; filament used [g] =");
            if (!target)
            {
                printf("O gcode não segue o padrão esperado.");
                return 0;
            }
            target = strchr(target, '=');
            target++;
            strncpy(material, target, strcspn(target, "\n;"));
            material[15] = '\0';

            target = strstr(gcode, "; estimated printing time (normal mode) =");
            if (!target)
            {
                printf("O gcode não segue o padrão esperado.");
                return 0;
            }
            target = strchr(target, '=');
            target++;
            strncpy(tempo, target, strcspn(target, "\n;"));
            tempo[15] = '\0';

            printf("Material: %s g;\n", material);
            printf("Tempo: %s \n", tempo);
            printf("O gcode tem: %ld bytes.\n", gcodeFileSize.st_size);

            free(gcode);
            close(gcodeFD);

            return 0;
        }
        
        perror("open");
        printf("Voce digitou um endereco valido?\n");

        return 0;
    }
    
    printf("Passe um argumento na chamada do programa.\n");
    
    return 0;
}
