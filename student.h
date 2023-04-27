bool isValidNumberOfStudents(int n) 
{
    if (n < 0 || n > 1000) 
    {
        return false;
    }
    return true;
}


bool isDuplicateID(student students[], int n, char id[]) {
    for (int i = 1; i < n; ++i) {
        if (strcmp(students[i].id, id) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidGrade(float grade[]) {
    for (int i = 0; i < 3; ++i) {
        if (grade[i] < 0 || grade[i] > 20) {
            return false;
        }
    }
    return true;
}

bool isValidBirthdate(int day, int month, int year) {
    int daymax;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daymax = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daymax = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                daymax = 29;
            } else {
                daymax = 28;
            }
            break;
    }
    if (day < 1 || day > daymax || month < 1 || month > 12 || year < 1) {
        return false;
    }
    return true;
}
