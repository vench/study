namespace myApp {

    using System;
    using System.Reflection;
    using System.Collections.Generic;

    class CommonInfo : AbRunnable {
 

          protected override void run() {
            Console.Clear();
            Console.WriteLine("Общая информация по типам");

            Assembly myAsm = Assembly.GetExecutingAssembly();
            Assembly[] refAssemblies = AppDomain.CurrentDomain.GetAssemblies();

            List<Type> types = new List<Type>();
            foreach(Assembly asm in refAssemblies)
                types.AddRange(asm.GetTypes());

            uint nRefTypes = 0, nValueTypes = 0, nInterTypes = 0;
            Type maxMethods = null;
            string maxLenMenthodName = null;
            MethodInfo maxLenArgsMenthodName = null;
            foreach(var t in types) {
                if(t.IsClass) {
                    nRefTypes ++;
                } 
                if(t.IsValueType) {
                    nValueTypes ++;    
                }       
                if(t.IsInterface) {
                    nInterTypes ++;
                }
                if(maxMethods == null || t.GetMethods().Length > maxMethods.GetMethods().Length) {
                    maxMethods = t;
                }
                
                foreach(var m in  t.GetMethods()) {
                    if(maxLenMenthodName == null || m.Name.Length > maxLenMenthodName.Length) {
                        maxLenMenthodName =  m.Name;
                    }
                    if(maxLenArgsMenthodName == null || maxLenArgsMenthodName.GetParameters().Length < m.GetParameters().Length) {
                        maxLenArgsMenthodName = m;
                    }
                }
            }        

            Console.WriteLine(@"
            Подключенные сборки: {0} 
            Всего типов по всем подключенным сборкам: {1}
            Ссылочные типы: {2}
            Значимые типы: {3}
            Типы - интерфейсы: {4}
            Тип с максимальным числом методов: {5}
            Самое длинное название метода: {6}
            Метод с наибольшим числом аргументов: {7}
            ", 
            refAssemblies.Length, 
            types.Count, 
            nRefTypes,
            nValueTypes, 
            nInterTypes, 
            maxMethods.Name, 
            maxLenMenthodName, 
            maxLenArgsMenthodName.Name  );

            Console.WriteLine("Нажмите любую клавишу, чтобы вернуться в главное меню");
            Console.ReadKey();  
            Stop();
          }  
    }
}