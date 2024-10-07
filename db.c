#include<stdio.h>
#include <dirent.h>
#include <direct.h>

char final[100] = "/Data";
void create(char *table, char *path) {
    FILE *fptr;
    char fold[100];
    sprintf(fold, "Data\\%s\\%s.txt", path, table);
    fptr = fopen(fold, "a+");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char myString[100];

    
    while(fgets(myString, 100, fptr)) {
        printf("%s", myString);
    }

    // Print the file content
    printf("%s", myString);
if(fptr == NULL) {
  printf("Not able to open the file.");
}
// Close the file
    fclose(fptr);
}




void dbname()
{
    char folderName[100];
    char fullPath[150];

    printf("Enter the name of the DataBase you want to create: ");
    scanf("%s", folderName);
    sprintf(fullPath, "Data//%s", folderName);

    // Create the directory
    if (_mkdir(fullPath) == 0) {
        printf("DataBase '%s' created successfully.\n", folderName);
    } else {
        perror("Error creating DataBase\n");
    }
}



int ls(char* db) {
  DIR *d;
  struct dirent *dir;
  char path[200];
  sprintf(path, ".%s", db);

  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  else
  {
    printf("\n*No Tables*\n");
    return 1;
  }
  
}



void ul()
{
  printf("----------------------------------------------\n");
}


void main()
{
  
  _mkdir("./Data");
  ul();
  printf("Welcome To GDB\n");
  ul();
  
    printf("Current DataBases\n");
    ul();
    ls(final);
    ul();
    printf("Create DataBase->1\nChoose DataBase->2\n->");
    char choice;
    scanf(" %c",&choice);
    ul();
    if(choice=='1')
    {
      dbname();
      ul();
      
    }
    else if (choice=='2')
    {
      printf("Enter DataBase Name:");
      char db[100];
      sprintf(db, "/");
      scanf("%s",&db);
      printf("DataBase Has been Choosed\n");
      ul();
      printf("*Current_Tables*\n");
      if(ls(db))
      {
        char tableName[100];  
        printf("Enter Table Name: ");
        scanf("%s", tableName);
        char *slash = strchr(db, '/');
          if (slash != NULL) {
            memmove(slash, slash + 1, strlen(slash));
          }

        create(tableName, db);
      }
      else{
      	ul();
	  }
    }
  
}