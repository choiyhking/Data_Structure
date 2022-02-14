#pragma once

typedef int Key;
typedef int Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot {
	Key key;
	Value value;
	enum SlotStatus status;
}Slot;