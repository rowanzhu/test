#include <cstdio>
#include <boost/interprocess/managed_mapped_file.hpp>
#include <boost/interprocess/containers/vector.hpp>

using namespace boost::interprocess;

typedef allocator<int, managed_mapped_file::segment_manager> mmap_alloc;
typedef vector<int, mmap_alloc> bipVec;

int main()
{
    //managed_mapped_file::grow("./MyMappedFile", 1000);
    //managed_mapped_file::shrink_to_fit("./MyMappedFile");
    
    managed_mapped_file mfile(open_or_create, "./MyMappedFile", 2000);
    mmap_alloc alloc(mfile.get_segment_manager());
    bipVec *pVec = mfile.find_or_construct<bipVec>("MyVector")(alloc);

    /*for(int i = 0; i < 100; ++i)
    {
        pVec->push_back(i + 1);
    }*/

    printf("|");
    bipVec::iterator iter;
    for(iter = pVec->begin(); iter != pVec->end(); ++iter)
    {
        printf("%d|", *iter);
    }
    printf("\n");

    return 0;
}
