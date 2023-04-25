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

void fifo(int n_pages, int *pages) {
    printf("FIFO Page Replacement Algorithm:\n");
    n_frames = 0;
    n_page_faults = 0;
    int oldest_index = 0;
    for (int i = 0; i < n_pages; i++) { // looping to go from the first page to the last page
        int page = pages[i]; // temporarily storing pages[i]
        if (find_page_index(page, n_frames, frames) == -1) { // checking if the page is present in the frames
            if (n_frames < MAX_FRAMES) {
                frames[n_frames++] = page; // assigning the page to a frame
            } else {
                frames[oldest_index++] = page; // assigning the page to a frame
                if (oldest_index == MAX_FRAMES) {
                    oldest_index = 0;
                }
            }
            n_page_faults++; // incrementing page faults count as the page is not present in frames
        }
        print_frames();
    }
    printf("Total Page Faults: %d\n", n_page_faults);
    printf("Total Pages: %d\n", n_pages);
    printf("Page Fault Ratio: %.2f\n\n", ((float)n_page_faults)/((float)n_pages));
}

int main( ) {
    int pages[] = {1, 2, 1, 3, 2, 4, 1, 5, 7, 2, 5, 6};
    int n_pages = sizeof(pages) / sizeof(pages[0]);
    
    fifo(n_pages, pages);
    
    return 0;
}