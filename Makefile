.PHONY:clean
main:linklist.c
	gcc $^ -o $@
clean:
	rm main
