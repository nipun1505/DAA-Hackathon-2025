#include <stdio.h>
#include <string.h>

#define MAX_MENTORS 3
#define MAX_SLOTS 3

struct Mentor {
    char name[50];
    char expertise[50];
    char slots[MAX_SLOTS][20];
    int slot_available[MAX_SLOTS];
};

void displayMentors(struct Mentor mentors[]) {
    printf("\nAvailable Mentors:\n");
    for (int i = 0; i < MAX_MENTORS; i++) {
        printf("\nMentor %d: %s (%s)\n", i + 1, mentors[i].name, mentors[i].expertise);
        for (int j = 0; j < MAX_SLOTS; j++) {
            printf("  Slot %d: %s [%s]\n", j + 1, mentors[i].slots[j],
                   mentors[i].slot_available[j] ? "Available" : "Booked");
        } 
    }
}

void bookSlot(struct Mentor mentors[]) {
    int mentor_choice, slot_choice;

    displayMentors(mentors);

    printf("\nEnter mentor number (1-%d): ", MAX_MENTORS);
    scanf("%d", &mentor_choice);

    if (mentor_choice < 1 || mentor_choice > MAX_MENTORS) {
        printf("Invalid mentor selection.\n");
        return;
    }

    printf("Enter slot number (1-%d): ", MAX_SLOTS);
    scanf("%d", &slot_choice);

    if (slot_choice < 1 || slot_choice > MAX_SLOTS) {
        printf("Invalid slot selection.\n");
        return;
    }

    if (mentors[mentor_choice - 1].slot_available[slot_choice - 1]) {
        mentors[mentor_choice - 1].slot_available[slot_choice - 1] = 0;
        printf("Booking confirmed with %s at %s!\n",
               mentors[mentor_choice - 1].name,
               mentors[mentor_choice - 1].slots[slot_choice - 1]);
    } else {
        printf("Sorry, that slot is already booked.\n");
    }
}

int main() {
    struct Mentor mentors[MAX_MENTORS] = {
        {"Dr. Asha Sharma", "AI & ML", {"10:00 AM", "2:00 PM", "4:00 PM"}, {1, 1, 1}},
        {"Mr. Rahul Mehta", "Cybersecurity", {"11:00 AM", "1:00 PM", "3:00 PM"}, {1, 1, 1}},
        {"Ms. Priya Nair ", "Data Science", {"9:30 AM", "12:00 PM", "5:00 PM"}, {1, 1, 1}}
    };

    int choice;
    do {
        printf("\n=== Mentor Connect Booking System ===\n");
        printf("1. View Mentors\n");
        printf("2. Book a Slot\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayMentors(mentors);
            break;
        case 2:
            bookSlot(mentors);
            break;
        case 3:
            printf("Thank you for using Mentor Connect!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
