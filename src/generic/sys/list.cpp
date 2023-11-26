#include <sys/list.hpp>

void AddElementToList(ListHead *element, List *list) {
	if (list->Head == NULL) {
		list->Head = element;
		element->Previous = NULL;
	}

	if (list->Tail == NULL) {
		list->Tail = element;
		element->Next = NULL;
	} else {
		ListHead *oldTail = list->Tail;
		oldTail->Next = element;
		element->Previous = oldTail;
		list->Tail = element;
	}
}

void AddElementToList(ListHead *element, ListHead *prev, List *list) {
	if (prev == NULL) {
		AddElementToList(element, list);
	} else {
		if (prev->Next == NULL) {
			list->Tail = element;
			prev->Next = element;
		} else {
			ListHead *oldNext = prev->Next;
			prev->Next = element;
			oldNext->Previous = element;
			element->Previous = prev;
			element->Next = oldNext;
		}
	}
}

void MoveElementToList(ListHead *element, List *origin, List *destination) {
	if (element == origin->Head) {
		origin->Head = element->Next;

		if (element->Next != NULL) {
			element->Next->Previous = NULL;
		}
	}

	if (element == origin->Tail) {
		origin->Tail = element->Previous;

		if (element->Previous != NULL) {
			element->Previous->Next = NULL;
		}
	}

	if (destination->Head == NULL) {
		element->Previous = NULL;
		destination->Head = element;
	}
		
	element->Next = NULL;

	if (destination->Tail == NULL) {
		destination->Tail = NULL;
	} else {
		ListHead *oldTail = destination->Tail;
		element->Previous = oldTail;
		oldTail->Next = element;
		destination->Tail = element;
	}

}
