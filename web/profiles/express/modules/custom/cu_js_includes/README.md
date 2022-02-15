# Adding JavaScript Includes

## Purpose of JavaScript Includes
- Fullfill our users' requests for adding 3rd party functionality to their websites with an easy to use interface.
- To create a uniform way for developers to add and manage 2nd and 3rd party website functionality.

## Add a JavaScript Include to Drupal 7 Web Express
1. Add line to .install file for including it in the variable database table.
    - go to `function cu_js_install()` on L81.
    - inside th `$types` array definition add your javascript include following the pattern of the others found there.
2. If your js include defines a block to be placed using the block/region layout tools:
    - add its name to the `$type = array('statuspage', 'slateform');` array definition in cu_js_includes.module file, in the cu_js_includes_block_options() function.
    - You can probably skip step 3.
3. If your js include defines a block to be placed via a context reaction:
    - You will probably skip step 2.
    - put the include name in the $types array found on line 28 of cu_js_includes.context.inc instead
4. Create a form function `cu_js_includes_<yourIncludeName>_form()` in `includes/cu_js_includes.forms.inc`:
    - take the other form functions guides and make whatever adjustments needed.
5. Add you include to the `includes/cu_js_includes.permissions.inc` to the `cu_js_includes_secure_permissions()` function:
    - Again, follow the pattern established there.
6. Add your js include to the `$custom_types` array inside `cu_js_includes_get_include_types()` found in the `cu_js_includes.types.inc` file:
    - Look previous includes for guidance
    - Make sure the value for the key `form_callback` matches the function you created in step 4 -> `'form_callback' => 'cu_js_includes<yourIncludeName>_form',`
7. Add js include to [types] array in `cu_js_includes_express_node_list_groups()` in `cu_js_includes.types.inc` file:
    - Follow the pattern found there with other includes
8. Add a template file:
    - create a file `<yourJsIncludeName>.tpl.php`
    - The elements and layout of the template may be somewhat dictated by the 3rd party you are trying to incorporate, but, again, use the other templates as guides.
