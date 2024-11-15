# FILEMAPPING
OS SHISH

1. BUDDY SYSTEM

   Allocates memory from fixed segment( prior that it has fixed size, or else no bro it won't)
   How memory is allocatedd??? ahh yess ->pwer-of-2 Allocator

   /* algo>

const int memory_seg=256kb;
kernal_request-> main mem= 21Kb // memory//

for i to memory 
    AL -> 128 KB;
    AR -> 128 KB;

    for j in (AL TO AR):
        int bl =AL/2 -> 64KB;
        int br= AR/2 -> 64KB;

further it is divided into CL AND CR , I Guess u can figure it out how it works.
nested loops are the best for this one,for generally would take O(n^2) but depends on the no memory_seg ;


        
