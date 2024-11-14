#include <windows.h>
#include <stdio.h>

//SHAME I HAD TO SWITCH TO WINDOWS TO COMPILE THIS 
//I KNOW IT'S NOT THE BEST, BUT IT WORKS
int main(int argc, char *argv[]){


    //inorder for the mapping to be done between the files
    /*
    We basically need to create hFiles and hMapFiles 
    these are majory used for mapping.
    */
    HANDLE hFile,hMapFile;
    LPVOID lpMapAddress;


    hFile=CreateFile(
        "Better say Heli.txt",
        GENERIC_READ | GENERIC_WRITE,// giving permission.
        0,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL   // if a guy is willing to add some file template or some shit, we can set it true.or
          // assign a boolean value according 1-> True ,0-> FALSE.
    );

    // file mapping objects 
    hMapFile=CreateFileMapping(
        hFile,
        NULL,
        PAGE_READWRITE,
        0,
        0,
        Text("SharedObject")  // so that the customer can see shit 
    );

    lpMapAddress=MapViewofFile(
        hMapFile,
        GENERIC_READ | GENERIC_WRITE  // can be given FILE_MAP_ALL_ACEESs, what i have observed is old cpp versions aren't familerized with all access
        0,
        0,
        0,
    );

    printf((char *)lpMapAddress, "Shared memory message");

    // Step 5: Clean up by unmapping the file view and closing handles
    UnmapViewOfFile(lpMapAddress);
    CloseHandle(hFile);
    CloseHandle(hMapFile);
}
