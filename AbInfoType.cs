namespace myApp {


    using System;
    using System.Collections.Generic;
    abstract class AbInfoType : AbRunnable {

        protected void showAboutType(Type t) {
            var fieldsName = new List<string>();
            foreach(var item in t.GetFields()) { 
                fieldsName.Add(item.Name);
            }

            Console.Clear();
            Console.WriteLine( @"
                Информация по типу: {0}
                Значимый тип: {1}
                Пространство имен: {2}
                Сборка: {3}
                Общее число элементов: {4}
                Число методов: {5}
                Число свойств: {6}
                Число полей: {7}
                Список полей: {8}

                Список свойств: - Нажмите ‘M’ для вывода дополнительной информации по методам
                Нажмите ‘0’ для выхода в главное меню
                Нажмите любую клавишу, чтобы вернуться в меню", 
                t.FullName, 
                t.IsValueType ? '+' : '-',
                t.Namespace,
                t.Assembly.FullName,
                t.GetMethods().Length + t.GetFields().Length + t.GetProperties().Length,
                t.GetMethods().Length,
                t.GetProperties().Length,
                t.GetFields().Length,
                String.Join(',', fieldsName)
                );
            
            var key = Console.ReadKey();
 
            switch(key.Key) {
                case ConsoleKey.D0: Stop(); break;
                case ConsoleKey.M:  
                    showInfoAboutMethods(t); 
                    showAboutType(t);
                    return; 
            }  
           
        }

        protected void showInfoAboutMethods(Type t) {

             string bufer = "";
             int maxLen = 0;
             var map = new Dictionary<string, int[]>();
             foreach(var item in t.GetMethods()) {
                if(!map.ContainsKey(item.Name)) {
                    map.Add(item.Name, new int[3]);
                    map[item.Name][1] = item.GetParameters().Length;
                    map[item.Name][2] = item.GetParameters().Length; 
                } else {
                    if(item.GetParameters().Length < map[item.Name][1]) {
                        map[item.Name][1] = item.GetParameters().Length;
                    }
                    if(item.GetParameters().Length > map[item.Name][2]) {
                        map[item.Name][2] = item.GetParameters().Length;
                    }
                }
                map[item.Name][0] ++; 

                if (maxLen < item.Name.Length) {
                    maxLen = item.Name.Length;
                }
             }

             foreach(var pair in map) {                   
                 bufer += pair.Key;
                 bufer += new string(' ', maxLen - pair.Key.Length);
                 bufer += "\t"+ pair.Value[0];
                 if(pair.Value[1] == pair.Value[2]) {
                   bufer += "\t\t\t" + pair.Value[1] + "\n\t\t";     
                 } else {
                   bufer += "\t\t\t" + pair.Value[1] + "..." + pair.Value[2] + "" + "\n\t\t"; 
                 }
             }
             
             Console.Clear();
             Console.WriteLine(@"
                Методы типа {0}
                
                Название{1}     Число перегрузок        Число параметров
                {2}
                
                Нажмите любую клавишу, чтобы вернуться в меню",
                t.FullName,
                new string(' ', maxLen - "Название".Length),
                bufer
                ); 
             Console.ReadKey(); 
        }
    }
}