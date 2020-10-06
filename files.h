#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <string>
#include <errno.h>
namespace direct
{
    FILE *fh;
    void create(std::string path)
    {
        if(fopen(path.c_str(),"r")!=NULL)
            std::cout<<"The file exists."<<std::endl;
        else
        {
            fh= fopen(path.c_str(),"w");
            fclose(fh);    
        }         
    }
    
    size_t length(std::string path)
    {
        size_t len;
        FILE *fh=fopen("line.txt","r");
        char temp=(char)(fgetc(fh));
        while(temp != EOF)
        {
            
            temp=(char)(fgetc(fh));
            if(temp!='\n')
            len++;        
        }
    fclose(fh);
    return len;
    }

    void empty(std::string path)
    {
       fh =fopen(path.c_str(),"w");
       fclose(fh);
    }
   
    void write(std::string path, std::string information)
    {
        fh= fopen(path.c_str(), "a");
        fputs(information.c_str(), fh);
        fclose(fh);
    }
    
    void write(std::string path, char character)
    {
        fh= fopen(path.c_str(), "a");
        fputc(character,fh);
        fclose(fh);
    }

    void overwrite(std::string path, std::string information)
    {
        fh= fopen(path.c_str(), "w");
        fputs(information.c_str(), fh);
        fclose(fh);
    }   
     
    
    std::string read(std::string path)
    {
        std::string information;
        fh = fopen(path.c_str(),"r");
        if(fh==NULL)
            throw "File Not Found";
        else
        {           
            char temp;
            do
            {
                temp=(char)(fgetc(fh));
                information+=temp;
                
            } while(temp != EOF);
        }
        return information;
    }
    
    void print(std::string path)
    {
        std::string information;
        fh = fopen(path.c_str(),"r");
        if(fh==NULL)
            throw errno;
        else
        {           
            char temp;
            do
            {
                temp=(char)(fgetc(fh));
                information+=temp;
                
            } while(temp != EOF);
        }
        std::cout<< information<<std::endl;
    }

}

// Using OOP file handling when extended use is expected
class files{
    protected:
        FILE *fh;
        const char *PATH;
        files(){};
        
    public:

    size_t len=0;
        
        files(const char* path,const char* mode):PATH(path)
        {
            len=direct::length(path);
            fh= fopen(path, mode);

        }
 
        files(const char* path):PATH(path)
        {
            len=direct::length(path);
            fh= fopen(path,"a+");
        }
        
        
      
       
        void empty()
        {
            fclose(fopen(PATH,"w")); 
            len=direct::length(PATH);  
        }

        void write(std::string information)
        {
            fputs(information.c_str(), fh);
            len=direct::length(PATH);
        }
        
        void write(std::string path, char character)
        {
            fputc(character,fh);
            len=direct::length(PATH);
        }

        void overwrite(std::string information)
        {
            FILE *fh= fopen(PATH, "w");
            fputs(information.c_str(), fh);
            fclose(fh);
            len=direct::length(PATH);
        }   
        
        
        std::string read()
        {
            std::string information;
            char temp;
            
            do
            {
                temp=(char)(fgetc(fh));
                information+=temp;
            
            }while(temp != EOF);


            return information;

        }
        

};

#endif
