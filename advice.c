#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static const char* advices[] = {
	"Будь высокомерен!",
	"Кто не любит одиночества, тот не любит свободы.",
	"Не давай жалким людишкам загрузить тебя!",
	"Получай от жизни удовольствие!",
	"Начинай каждое утро с кофе и 100 г шоколада (минимум 75%).",
	"Борись за свою свободу!",
	"Надо ебашить!",
	"Кто не ебашит, не добивается результата!",
	"Люди отдали бы ВСЕ, чтобы быть на твоем месте!",
	"Не дай обществу сломить тебя!",
	"Кто ты? Чего ты хочешь?",
	"Клади хуй на чужое мнение!",
	"Не позволяй жалким людишкам манипулировать тобой!",
};


unsigned int
hash(const char *data, const size_t data_len) {
	unsigned int hash = 31337;
	for(int i = 0; i < data_len; i++) {
		hash = ((hash << 5) + hash) + data[i];
	}
	return hash;
}

int
main()
{
	struct timeval time = {0};
	gettimeofday(&time, NULL);

	/* srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); */
	srand(hash((const char*)&time, sizeof(time)));

	int idx = (sizeof(advices)/sizeof(advices[0])) * (((double)rand()) / ((double)RAND_MAX));
	printf("%s\n", advices[idx]);
	return 0;
}
