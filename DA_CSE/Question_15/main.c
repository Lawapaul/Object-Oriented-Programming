#include <stdio.h>


int main() {
    int m, n;

    // Input the number of students (m) and the number of days (n)
    printf("Enter the number of students: ");
    scanf("%d", &m);
    printf("Enter the number of days in the month: ");
    scanf("%d", &n);

    // Data representing student attendance
    char data[31][10];

    // Input the attendance data for each day
    printf("Enter the attendance data for each day (P for present, A for absent):\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf(" %c", &data[i][j]);
        }
    }

    // i. Find the maximum number of consecutive days on which all students were present
    int max_present = 0;
    int present_count = 0;
    int start_present = -1;
    for (int i = 0; i < n; i++) {
        int all_present = 1; // Assume all students are present
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 'A') {
                all_present = 0; // If any student is absent, set all_present to 0
                break;
            }
        }
        if (all_present) {
            present_count++;
            if (start_present == -1)
                start_present = i;
            if (present_count > max_present)
                max_present = present_count;
        } else {
            present_count = 0;
            start_present = -1;
        }
    }

    // ii. Find the maximum number of consecutive days on which all students were absent
    int max_absent = 0;
    int absent_count = 0;
    int start_absent = -1;
    for (int i = 0; i < n; i++) {
        int all_absent = 1; // Assume all students are absent
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 'P') {
                all_absent = 0; // If any student is present, set all_absent to 0
                break;
            }
        }
        if (all_absent) {
            absent_count++;
            if (start_absent == -1)
                start_absent = i;
            if (absent_count > max_absent)
                max_absent = absent_count;
        } else {
            absent_count = 0;
            start_absent = -1;
        }
    }

    // iii. Find the days in which the number of students present is greater than the number of students absent
    printf("present highest\n");
    for (int i = 0; i < n; i++) {
        int present = 0, absent = 0;
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 'P')
                present++;
            else
                absent++;
        }
        if (present > absent)
            printf("%d ", i + 1);
    }
    printf("\n");

    // iv. Find the days in which the number of students absent is greater than the number of students present
    printf("absent highest\n");
    for (int i = 0; i < n; i++) {
        int present = 0, absent = 0;
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 'P')
                present++;
            else
                absent++;
        }
        if (absent > present)
            printf("%d ", i + 1);
    }
    printf("\n");

    // v. Find the days in which the number of students present and absent is equal
    printf("present absent equal\n");
    for (int i = 0; i < n; i++) {
        int present = 0, absent = 0;
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 'P')
                present++;
            else
                absent++;
        }
        if (present == absent)
            printf("%d ", i + 1);
    }
    printf("\n");

    // Displaying the maximum consecutive days where all students were present
    printf("consecutive days present\n");
    printf("%d\n", max_present);
    if (max_present > 0) {
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(data[i][j]== 'P'){
                    count+=1;
                }
            }
            if(count==m){
                printf("%d ",i+1);
            }
        }
    }

    printf("\nconsecutive days Absent\n");
    printf("%d\n", max_absent);
    if (max_absent > 0) {
        for(int i=0;i<m;i++){
            int count1=0;
            for(int j=0;j<n;j++){
                if(data[i][j]== 'A'){
                    count1+=1;
                }
            }
            if(count1==m){
                printf("%d ",i+1);
            }
        }
    }

    return 0;
}
