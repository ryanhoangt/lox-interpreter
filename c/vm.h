#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
	Chunk* chunk;
	uint8_t* ip; // instruction pointer (or program counter)
	Value stack[STACK_MAX];
	Value* stackTop; // pointer to the array element just past the top value
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();

void freeVM();

InterpretResult interpret(Chunk* chunk);

void push(Value value);

Value pop();

#endif
