#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ReadSizeFile(const char *file_path, int size[4])
{
    FILE *file;
    file = fopen(file_path, "rt+");
    if (!file) //条件不成立，则说明文件打开失败
    {
        fclose(file);
        cout << "打开文件失败！ " << endl;
    }
    fscanf(file, "Float32(%d, %d, %d, %d)", &size[0], &size[1], &size[2], &size[3]);
    fclose(file);
}
void ReadTDFfile(const char *file_path, vector<vector<vector<float>>>& object_TDF_data, int size[4]){
    FILE *pFile;
    long lSize;
    char *buffer;
    size_t result;
    pFile = fopen(file_path, "rb");
    if (pFile == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }
    // obtain file size:
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);   // 指针倒带至头
    // allocate memory to contain the whole file:
    buffer = (char *)malloc(sizeof(char) * lSize);
    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        exit(2);
    }
    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, pFile);
    if (result != lSize)
    {
        fputs("Reading error", stderr);
        exit(3);
    }

    float* f = (float*)buffer;
    /* the whole file is now loaded in the memory buffer. */
    for(int i=0; i< size[0]; ++ i){
        vector<vector<float>> column_row;
        for(int j=0; j< size[1]; ++ j){
            vector<float> row;
            for(int k=0; k<size[2]; ++ k){
               row.push_back(*f);
               ++ f;
            }
            column_row.push_back(row);
            row.clear();
        }
        object_TDF_data.push_back(column_row);       
        column_row.clear();
    }
    // terminate
    fclose(pFile);
    free(buffer);
}

int main()
{
    const char *file_path_size = "bicycle000002.size";
    int size[4];
    ReadSizeFile(file_path_size, size);

    vector<vector<vector<float>>> object_TDF_data;
    cout << "the max_size of vector is: " << object_TDF_data.max_size() << endl;
    const char *file_path_data = "bicycle000002.raw";
    ReadTDFfile(file_path_data, object_TDF_data, size);
    return 0;
}