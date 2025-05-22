#include <stdio.h>

typedef union {
    unsigned int uintValue;
    unsigned char bytes[4];
} IntByteUnion;

int main() {
    IntByteUnion u;
    int input;

    printf("Enter the value of (int): ");
    scanf("%d", &input);

    u.uintValue = (unsigned int)input;

    printf("unsigned int: %u\n", u.uintValue);
    printf("Order of bytes:\n");

    for (int i = 0; i < 4; i++) {
        printf("byte %d: 0x%0X\n", i, u.bytes[i]);
    }

    return 0;
}

#include <stdio.h>

union ByteOrder {
    unsigned int intValue;
    unsigned char byteArray[4];
};


void determineByteOrder(int value) {
    union ByteOrder data;
    data.intValue = value;

    printf("Байты числа %d в памяти (сначала младший байт):\n", value);
    for (int i = 0; i < 4; i++) {
        printf("byteArray[%d] = %02X\n", i, data.byteArray[i]);
    }

    if (data.byteArray[0] == (value & 0xFF)) {
        printf("Машина использует порядок байтов Little-Endian (младший байт впереди).\n");
    } else {
        printf("Машина использует порядок байтов Big-Endian (старший байт впереди).\n");
    }
}

int main() {
    int value;

    printf("Введите целое число: ");
    scanf("%d", &value);

    determineByteOrder(value);

    return 0;
}
