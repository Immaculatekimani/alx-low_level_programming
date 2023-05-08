#include "main.h"

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr elf_header;
    ssize_t bytes_read;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 98;
    }
    bytes_read = read(fd, &elf_header, sizeof(elf_header));
    if (bytes_read != sizeof(elf_header)) {
        fprintf(stderr, "Error: could not read ELF header from file %s\n", argv[1]);
        close(fd);
        return 98;
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 || elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: file %s is not an ELF file\n", argv[1]);
        close(fd);
        return 98;
    }

    printf("Magic: %02x %02x %02x %02x\n", elf_header.e_ident[EI_MAG0], elf_header.e_ident[EI_MAG1], elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
    printf("Class: %d-bit\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
    printf("Data: %s-endian\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI] == 0 ? "UNIX System V" : "Unknown");
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header.e_type);
    printf("Entry point address: 0x%lx\n", elf_header.e_entry);

    close(fd);
    return 0;
}
