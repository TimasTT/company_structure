add_subdirectory(company_structure)
add_subdirectory(parser)
add_subdirectory(commands)

set(company_structure_libs
        company_structure
        parser
        commands
        PARENT_SCOPE)
