#include <stdio.h>
#include <string.h>
#include "pharmacy.h"

// وظيفة لقراءة بيانات الأدوية من ملف
void loadMedicines(struct Medicine pharmacy[], int *medicineCount) {
    FILE *file = fopen("pharmacy_data.txt", "r");
    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f", pharmacy[*medicineCount].name, &pharmacy[*medicineCount].quantity, &pharmacy[*medicineCount].price) != EOF) {
        (*medicineCount)++;
    }
    
    fclose(file);
    printf("Data loaded successfully.\n");
}

// وظيفة لحفظ بيانات الأدوية إلى ملف
void saveMedicines(struct Medicine pharmacy[], int medicineCount) {
    FILE *file = fopen("pharmacy_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < medicineCount; i++) {
        fprintf(file, "%s %d %.2f\n", pharmacy[i].name, pharmacy[i].quantity, pharmacy[i].price);
    }
    
    fclose(file);
    printf("Data saved successfully.\n");
}

// وظيفة لإضافة دواء جديد إلى النظام
void addMedicine(struct Medicine pharmacy[], int *medicineCount) {
    printf("Enter medicine name: ");
    scanf("%s", pharmacy[*medicineCount].name);
    
    printf("Enter quantity: ");
    scanf("%d", &pharmacy[*medicineCount].quantity);
    
    printf("Enter price: ");
    scanf("%f", &pharmacy[*medicineCount].price);
    
    (*medicineCount)++;
    
    // حفظ البيانات بعد إضافة الدواء
    saveMedicines(pharmacy, *medicineCount);
}

// وظيفة لسحب الدواء عند الطلب
void withdrawMedicine(struct Medicine pharmacy[], int medicineCount) {
    char medicineName[50];
    int quantityToWithdraw;
    
    printf("Enter medicine name: ");
    scanf("%s", medicineName);
    
    printf("Enter quantity to withdraw: ");
    scanf("%d", &quantityToWithdraw);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(pharmacy[i].name, medicineName) == 0) {
            if (pharmacy[i].quantity >= quantityToWithdraw) {
                pharmacy[i].quantity -= quantityToWithdraw;
                printf("Medicine dispensed. Remaining quantity: %d\n", pharmacy[i].quantity);
                
                // حفظ البيانات بعد تحديث الكمية
                saveMedicines(pharmacy, medicineCount);
            } else {
                printf("Insufficient quantity!\n");
            }
            return;
        }
    }
    printf("Medicine not found!\n");
}

// وظيفة لعرض الأدوية المتاحة
void displayPharmacy(struct Medicine pharmacy[], int medicineCount) {
    printf("Available Medicines:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", pharmacy[i].name, pharmacy[i].quantity, pharmacy[i].price);
    }
}

// الوظيفة الرئيسية
int main() {
    struct Medicine pharmacy[100];
    int medicineCount = 0;
    int choice;
    
    // قراءة بيانات الأدوية من الملف عند بدء التشغيل
    loadMedicines(pharmacy, &medicineCount);
    
    do {
        printf("\n1. Add Medicine\n2. Withdraw Medicine\n3. Display Pharmacy\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(pharmacy, &medicineCount);
                break;
            case 2:
                withdrawMedicine(pharmacy, medicineCount);
                break;
            case 3:
                displayPharmacy(pharmacy, medicineCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
