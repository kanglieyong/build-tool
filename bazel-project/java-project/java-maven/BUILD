package(default_visibility = ["//visibility:public"])

java_library(
    name = "java-maven-lib",
    srcs = glob(["src/main/java/org/kly/myproject/*.java"]),
    deps = ["@com_google_guava_guava//jar"],
)

java_binary(
    name = "java-maven",
    main_class = "org.kly.myproject.App",
    runtime_deps = [":java-maven-lib"],
)

