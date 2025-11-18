#include <stdio.h>

int main() {
    int n, frames, pages[50], frame[10];
    int page_faults = 0, page_hits = 0;
    int i, j, k, flag, pos = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Initialize frames to -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage Reference -> Frames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already exists in frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                page_hits++;
                break;
            }
        }

        // If not found, replace oldest page (FIFO)
        if (flag == 0) {
            frame[pos] = pages[i];
            pos = (pos + 1) % frames; // circular FIFO replacement
            page_faults++;
        }

        // Print current frame contents
        printf("%2d -> ", pages[i]);
        for (k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%2d ", frame[k]);
            else
                printf(" - ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    printf("Total Page Hits = %d\n", page_hits);

    return 0;
}

