#ifndef RL_FILE_H_INCLUDED
#define RL_FILE_H_INCLUDED

class rl_file {
    int sizeVal;
    const char *dataVal;
    public:
    rl_file(int sizeVal, const char *dataVal);
    ~rl_file();
    void free();
    int size();
    const char *data();
};

#endif
