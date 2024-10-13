#ifndef PHARMACY_H
#define PHARMACY_H

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

void loadMedicines(struct Medicine pharmacy[], int *medicineCount);
void saveMedicines(struct Medicine pharmacy[], int medicineCount);
void addMedicine(struct Medicine pharmacy[], int *medicineCount);
void withdrawMedicine(struct Medicine pharmacy[], int medicineCount);
void displayPharmacy(struct Medicine pharmacy[], int medicineCount);

#endif // PHARMACY_H
