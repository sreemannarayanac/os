#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

int frames[MAX_FRAMES];  // array to store frames
int n_frames = 0;  // number of frames currently occupied
int n_page_faults = 0;  // number of page faults occurred

int find_page_index(int page, int n_pages, int *pages) {
    // find index of page in the array of pages
    for (int i = 0; i < n_pages; i++) {
        if (pages[i] == page) {
            return i;
        }
    }
    return -1;
}

void print_frames() {
    // print current state of frames
    printf("Frames: ");
    for (int i = 0; i < n_frames; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

void optimal(int n_pages, int *pages) {
    printf("Optimal Page Replacement Algorithm:\n");
    n_frames = 0;
    n_page_faults = 0;
    int next_index[MAX_FRAMES] = {0};
    for (int i = 0; i < n_pages; i++) {
        int page = pages[i];
        int index = find_page_index(page, n_frames, frames);
        if (index == -1) {
            if (n_frames < MAX_FRAMES) {
            frames[n_frames++] = page;
            } else {
                int furthest_index = 0;
                int max_next_index = next_index[0];
                for (int j = 1; j < n_frames; j++) {
                    if (next_index[j] > max_next_index) {
                        max_next_index = next_index[j];
                        furthest_index = j;
                    }
                }
                frames[furthest_index] = page;
            }
            n_page_faults++;
        }
        for (int j = 0; j < n_frames; j++) {
        if (frames[j] != page) {
                next_index[j]++;
            } else {
                next_index[j] = 0;
            }
        }
        print_frames();
    }
    printf("Total Page Faults: %d\n\n", n_page_faults);
}

int main( ) {
    int pages[] = {1, 2, 1, 3, 2, 4, 1, 5, 7, 2, 5, 6};
    int n_pages = sizeof(pages) / sizeof(pages[0]);
    
    optimal(n_pages, pages);
    
    return 0;
}