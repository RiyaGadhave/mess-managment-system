Code:#include <stdio.h>
#include <string.h>

struct menu {
    char breakfast[7][50];
    char lunch[7][50];
    char dinner[7][50];
};
struct feedback {
    char food[50];
    int rating;
    char comment[150];
};

struct timeEntry {
    char inTime[10];
    char outTime[10];
};
void welcome() {
    printf("=====================================\n");
    printf("       MESS MANAGEMENT SYSTEM\n");
    printf("=====================================\n");
    printf ("price for month =3600\n");
    printf ("price for one day =120\n");
    printf ("price for one time lunch /dinner =60\n");
    printf (" price for one time breakfast =30\n");
}

struct menu enterWeeklyMenu() {
    struct menu m;
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday",
     "Friday", "Saturday", "Sunday"};

    strcpy(m.breakfast[0], "Poha");
    strcpy(m.breakfast[1], "Idli");
    strcpy(m.breakfast[2], "Samosa");
    strcpy(m.breakfast[3], "Dosa");
    strcpy(m.breakfast[4], "Upma");
    strcpy(m.breakfast[5], "Thepla");
    strcpy(m.breakfast[6], "Pav Bhaji");

    strcpy(m.lunch[0], "Rice and Dal");
    strcpy(m.lunch[1], "Chapati and Sabzi");
    strcpy(m.lunch[2], "Pulao and Raita");
    strcpy(m.lunch[3], "Khichdi and Papad");
    strcpy(m.lunch[4], "Rajma Chawal");
    strcpy(m.lunch[5], "Veg Biryani");
    strcpy(m.lunch[6], "Chole Bhature");

    strcpy(m.dinner[0], "Roti and Paneer");
    strcpy(m.dinner[1], "Paratha and Curd");
    strcpy(m.dinner[2], "Veg Noodles");
    strcpy(m.dinner[3], "Dal Tadka and Rice");
    strcpy(m.dinner[4], "Pasta");
    strcpy(m.dinner[5], "Misal Pav");
    strcpy(m.dinner[6], "Soup and Bread");

    printf("\n--- Weekly Menu ---\n");
    for (int i = 0; i < 7; i++) {
        printf("%s:\n", days[i]);
        printf("  Breakfast: %s\n", m.breakfast[i]);
        printf("  Lunch: %s\n", m.lunch[i]);
        printf("  Dinner: %s\n\n", m.dinner[i]);
    }
    return m;
}


int login() {
    char username[50], password[50];
    char correct_username[] = "canteen";
    char correct_password[] = "canteen@123";

    printf("Login\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Login failed!\n");
        return 0;
    }
}

struct feedback collectFeedback() {
    struct feedback f;

    printf("\n--- Feedback Form ---\n");
    printf("Enter the food item: ");
    scanf(" %[^\n]", f.food);

    printf("Rate the food (1 to 5): ");
    scanf("%d", &f.rating);

    printf("Enter your comment: ");
    scanf(" %[^\n]", f.comment);

    return f;
}

void displayFeedback(struct feedback f) {
    printf("\n--- Feedback Summary ---\n");
    printf("Food Item: %s\n", f.food);
    printf("Rating: %d / 5\n", f.rating);
    printf("Comment: %s\n", f.comment);
}
struct timeEntry getTimeFromUser() {
    struct timeEntry t;
    printf("\n--- Enter Time ---\n");
    printf("Enter In-Time (HH:MM): ");
    scanf("%s", t.inTime);
    printf("Enter Out-Time (HH:MM): ");
    scanf("%s", t.outTime);
    return t;
}

int main() {
    welcome();

    if (!login()) {
        return 0;
    } struct menu m = enterWeeklyMenu();

    struct timeEntry t = getTimeFromUser();
    printf("\nTime Recorded:\nIn-Time: %s\nOut-Time: %s\n",
     t.inTime, t.outTime);

    struct feedback f = collectFeedback();
    displayFeedback(f);

    return 0;
}
