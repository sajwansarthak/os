#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, pages[30], frames[10], time[10];
    int counter = 0, flag1, flag2, i, j, pos, page_faults = 0, page_hits = 0;

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string: ");
    for (i = 0; i < no_of_pages; ++i)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    printf("\nPage Reference -> Frames\n");

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if page is already in a frame (HIT)
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                page_hits++;
                break;
            }
        }

        // If page not found (MISS)
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame, replace LRU page
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            page_faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        // Print current frame contents
        printf("%2d -> ", pages[i]);
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%2d ", frames[j]);
            else
                printf(" - ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    printf("Total Page Hits = %d\n", page_hits);

    return 0;
}

