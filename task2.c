#include <stdio.h>
#include <ctype.h>

float convertToCelsius(float val, char scale) {
    if (scale == 'F') return (val - 32.0f) * 5.0f / 9.0f;
    if (scale == 'K') return val - 273.15f;
    return val;
}

float convertFromCelsius(float c, char scale) {
    if (scale == 'F') return (c * 9.0f / 5.0f) + 32.0f;
    if (scale == 'K') return c + 273.15f;
    return c;
}

int main() {
    float val;
    char scale, target;

    printf("Enter the temperature value: ");
    if (scanf("%f", &val) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &scale);
    scale = toupper(scale);
    if (scale != 'C' && scale != 'F' && scale != 'K') {
        printf("Invalid scale. Must be C, F, or K.\n");
        return 1;
    }

    // Absolute zero validations
    if ((scale == 'K' && val < 0.0f) || 
        (scale == 'C' && val < -273.15f) || 
        (scale == 'F' && val < -459.67f)) {
        printf("Invalid temperature: Cannot be below absolute zero.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &target);
    target = toupper(target);
    if (target != 'C' && target != 'F' && target != 'K') {
        printf("Invalid target scale. Must be C, F, or K.\n");
        return 1;
    }

    float celsius = convertToCelsius(val, scale);
    float result = convertFromCelsius(celsius, target);

    printf("Converted temperature: %.2f %c\n", result, target);

    const char* category;
    const char* advisory;

    if (celsius < 0.0f) {
        category = "Freezing";
        advisory = "Wear a heavy coat and stay warm.";
    } else if (celsius < 10.0f) {
        category = "Cold";
        advisory = "Wear a jacket.";
    } else if (celsius < 25.0f) {
        category = "Comfortable";
        advisory = "Enjoy the nice weather!";
    } else if (celsius < 35.0f) {
        category = "Hot";
        advisory = "Drink lots of water!";
    } else {
        category = "Extreme Heat";
        advisory = "Stay indoors and hydrate immediately!";
    }

    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}