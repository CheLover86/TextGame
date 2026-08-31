#include <stdio.h>
#include <stdbool.h>
#include "object.h"
#include "match.h"
#include "reach.h"

int executeOpen(void) {
	OBJECT *obj = reachableObject("what you want to open", params[0]);
	if (obj != NULL) (*obj->open)();
	return 1;
}
int executeClose(void) {
	OBJECT *obj = reachableObject("what you want to close", params[0]);
	if (obj != NULL) (*obj->close)();
	return 1;
}
int executeLock(void) {
	OBJECT *obj = reachableObject("what you want to lock", params[0]);
	if (obj != NULL) (*obj->lock)();
	return 1;
}
int executeUnlock(void) {
	OBJECT *obj = reachableObject("what you want to unlock", params[0]);
	if (obj != NULL) (*obj->unlock)();
	return 1;
}
