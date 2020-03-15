#ifndef RL_FILE_H_INCLUDED
#define RL_FILE_H_INCLUDED

/**
 * Orion "KeinR" Musselman
 * Version 1.1
 */

class rl_file {
    int sizeVal;
    const char *dataVal;
    public:
    rl_file(int sizeVal, const char *dataVal);
    ~rl_file();
    void free();
    int size() const;
    const char *data() const;
};

#endif
