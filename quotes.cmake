add_custom_command(
        PRE_BUILD
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/quotes.o
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_OBJCOPY} --input binary --output elf32-littlearm quotes.txt quotes.o
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/quotes.txt
)
