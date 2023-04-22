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

void lru(int n_pages, int *pages) {
    printf("LRU Page Replacement Algorithm:\n");
    n_frames = 0;
    n_page_faults = 0;
    int oldest_index = 0;
    int *age = calloc(MAX_FRAMES, sizeof(int));
    for (int i = 0; i < n_pages; i++) {
        int page = pages[i];
        int index = find_page_index(page, n_frames, frames);
        if (index == -1) {
            if (n_frames < MAX_FRAMES) {
                frames[n_frames++] = page;
                age[n_frames-1] = i;
            } else {
                int min_age = age[0];
                oldest_index = 0;
                for (int j = 1; j < n_frames; j++) {
                    if (age[j] < min_age) {
                        min_age = age[j];
                        oldest_index = j;
                    }
                }
                frames[oldest_index] = page;
                age[oldest_index] = i;
            }
            n_page_faults++;
        } else {
            age[index] = i;
        }
        print_frames();
    }
    printf("Total Page Faults: %d\n\n", n_page_faults);
    free(age);
}

int main( ) {
    int pages[] = {1, 2, 1, 3, 2, 4, 1, 5, 7, 2, 5, 6};
    int n_pages = sizeof(pages) / sizeof(pages[0]);
    
    lru(n_pages, pages);
    
    return 0;
}