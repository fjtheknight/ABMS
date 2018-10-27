<? ini_set('max_input_vars', 30500);
phpinfo(); 
echo ini_get('max_input_vars');

if (!ini_get('max_input_vars')) {
    ini_set('max_input_vars', 30500);
}

echo ini_get('max_input_vars');?>