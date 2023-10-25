#include <blib.h>

size_t strlen(const char *s) {
//	panic("please implement");
	size_t i;
	size_t num = 0;
	for(i = 0;*(s+i) != '\0';i++){
		num++;
	}
	return num;
}

char *strcpy(char *dst, const char *src) {
//	panic("please implement");
	size_t i;
	for(i = 0;*(src+i) != '\0';i++){
		dst[i] = src[i];
	}	
	dst[i] = '\0';
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
	char *res = dst;
	while (*src && n--) {
		*dst++ = *src++;
	}
	*dst = '\0';
	return res;
}

char *strcat(char *dst, const char *src) {
	//panic("please implement");
	size_t dst_len = strlen(dst);
	size_t i;
	for(i = 0;src[i] != '\0';i++){
		dst[dst_len + i] = src[i];
	}
	dst[dst_len + i] = '\0';
	return dst;

}

int strcmp(const char *s1, const char *s2) {
	//panic("please implement");
	int ret = 0;
	while(!(ret = *(unsigned char *)s1-*(unsigned char *)s2) && *s1 != '\0') {
		s1++;
		s2++;
	}
	if(ret != 0){
		return ret;
	}
	return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	while (n--) {
		if (*s1 != *s2) {
			return *s1 - *s2;
		}
		if (*s1 == 0) {
			break;
		}
		s1++;
		s2++;
	}
	return 0;
}

void *memset(void *s, int c, size_t n) {
//	panic("please implement");
	size_t i;
	for(i = 0;i < n;i++){
		*(char *)(s+i) = c; 	
	}
	return s;
}

void *memcpy(void *out, const void *in, size_t n) {
	char *csrc = (char *)in;
	char *cdest = (char *)out;
	for (int i = 0; i < n; i++) {
		cdest[i] = csrc[i];
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	//panic("please implement");
	if(n == 0){
		return 0;
	}
	while(--n && *(char *)s1 == *(char *)s2){
		s1 = (char *)s1 + 1;
		s2 = (char *)s2 + 1;
	}
	return *(char *)s1 - *(char *)s2;
}
