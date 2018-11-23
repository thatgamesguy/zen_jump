all: guard-ANDROID_HOME
	ant clean
	ant debug install

clean: guard-ANDROID_HOME
	ant clean

guard-%:
	@ if [ "${${*}}" == "" ]; then \
		echo "Environment variable $* not set"; \
		exit 1; \
	fi
