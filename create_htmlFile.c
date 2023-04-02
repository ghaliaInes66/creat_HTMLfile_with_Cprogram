#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
	char username[20];
	char name[10];
	char image[20];
};


int main(int argc, char *argv[]) {
	FILE *user_file;
	user_file=fopen(argv[1],"r");
		if(user_file==NULL){
			printf("incorrect username");
		}
		else{
			int i; char pas[8];
			fscanf(user_file,"%s",pas);
			if(strcmp(pas,argv[2])){
				printf("incorrect password");
			}
			else{
				struct user user;
				fscanf(user_file,"%s",user.username);
				fscanf(user_file,"%s",user.name);
				fscanf(user_file,"%s",user.image);
				FILE *profile_file;
				profile_file=fopen("profile.html","w");
			    fprintf( profile_file, "<HTML>"); 
                fprintf(profile_file , "<HEAD><link rel=stylesheet href=style.css> <TITLE> your profile</TITLE> </HEAD>" ); 
                fprintf( profile_file, "<BODY>"); 
                fprintf(profile_file,"  <div class=container> ");
				fprintf(profile_file," <div class=username> <h2>%s</h2></div>	<div class=profile_image> <img src=%s></div>  <div class=name> <h3>%s</h3></div> <div class=edit_profile><button>Edit profile</button></div> </div>",user.username,user.image,user.name);
                fprintf( profile_file, "</BODY>"); 
                fprintf( profile_file, "</HTML>");       
			   
  		fclose(profile_file );
			}
		}
	}
