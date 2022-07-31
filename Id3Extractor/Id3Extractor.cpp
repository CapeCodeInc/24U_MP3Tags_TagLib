// 
//

#include"Id3Extractor.h"
#include"taglib.h"
#include"taglib\fileref.h"

#include<id3v2tag.h>
#include<mpegfile.h>
#include<id3v2frame.h>
#include<id3v2header.h>
#include <attachedpictureframe.h>
#include<cstdio>
#include<string.h>

using File = TagLib::MPEG::File;
using Fileref = TagLib::File*;

int main(int argc, char* argv[])
{
    cout << "********************************************************************************\n";
    cout << "*                            Id3Extractor                                      *\n";
    cout << "********************************************************************************\n\n\n";

    if (argc < 2)
    {
        cout << "Nothing to work with. Please enter an absolute path to an mp3 file.\n\n\n";
        return 1;
    
    }
    
    TagLib::MPEG::File mpegFile(argv[1]);
    if (!mpegFile.isOpen())
    {
        cout << "Sorry, the command line input does not lead to a valid file.\n";
        cout<< "Please enter a single path to an mp3 file.\n\n\n";
        return 1;
    
    }
    
    cout << "The name of the song is: ";
    cout << mpegFile.tag()->title()<<endl<<endl<<endl;
    
    static const char* IdPicture = "APIC";
    TagLib::ID3v2::Tag* id3v2tag = mpegFile.ID3v2Tag();
    TagLib::ID3v2::FrameList Frame;
    TagLib::ID3v2::AttachedPictureFrame* PicFrame;
    void* RetImage = NULL, * SrcImage;
    unsigned long Size;

    FILE* jpegFile;
    fopen_s(&jpegFile, "Extracted Cover Art.jpg", "wb");

    if (id3v2tag)
    {
        // picture frame
        Frame = id3v2tag->frameListMap()[IdPicture];
        if (!Frame.isEmpty())
        {
            for (TagLib::ID3v2::FrameList::ConstIterator it = Frame.begin(); it != Frame.end(); ++it)
            {
                PicFrame = (TagLib::ID3v2::AttachedPictureFrame*)(*it);
                if ( PicFrame->type() == TagLib::ID3v2::AttachedPictureFrame::FrontCover)
                {
                    // extract image (in it’s compressed form)
                    Size = PicFrame->picture().size();
                    SrcImage = malloc(Size);
                    if (SrcImage && jpegFile)
                    {
                        memcpy(SrcImage, PicFrame->picture().data(), Size);
                        fwrite(SrcImage, Size, 1, jpegFile);
                        fclose(jpegFile);
                        free(SrcImage);
                    }

                }
            }
        }
    }
    else
    {
        cout << "id3v2 not present";
    }
    return(0);
}