import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';

// CECS 453
// Lab assignment 1
// Just Me: Carlos Aguilera

// Video Link: https://www.loom.com/share/109beb68d954441fb00ba015fd6b002d

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatelessWidget {
  const MyHomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          SizedBox(height: 200.0),
          Expanded(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  padding: EdgeInsets.all(10.0),
                  child: Image.asset(
                    'assets/images/stud.png',
                    width: 130.0,
                    semanticLabel: 'Student',
                  ),
                ),
                Text(
                  'Carlos Aguilera',
                  style: TextStyle(
                    fontSize: 38.0,
                    fontWeight: FontWeight.w500,
                    letterSpacing: 2.0,
                  ),
                ),
                SizedBox(height: 10.0),
                Text(
                  'Software Engineer',
                  style: TextStyle(fontSize: 30.0, fontWeight: FontWeight.bold),
                ),
              ],
            ),
          ),
          Expanded(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Row(
                  children: [
                    SizedBox(width: 100.0),
                    Semantics(
                      label: 'Phone',
                      child: SvgPicture.asset(
                        'assets/icons/phone.svg',
                        width: 40.0,
                        height: 40.0,
                      ),
                    ),
                    SizedBox(width: 20.0),
                    Text('+1 (555) 123-4567'),
                  ],
                ),
                SizedBox(height: 10.0),
                Row(
                  children: [
                    SizedBox(width: 100.0),
                    Semantics(
                      label: 'Contact',
                      child: SvgPicture.asset(
                        'assets/icons/contact.svg',
                        width: 40.0,
                        height: 40.0,
                      ),
                    ),
                    SizedBox(width: 20.0),
                    Text('@carlos_aguilera'),
                  ],
                ),
                SizedBox(height: 10.0),
                Row(
                  children: [
                    SizedBox(width: 100.0),
                    Semantics(
                      label: 'Email',
                      child: SvgPicture.asset(
                        'assets/icons/email.svg',
                        width: 40.0,
                        height: 40.0,
                      ),
                    ),
                    SizedBox(width: 20.0),
                    Text('carlos.aguilera@example.com'),
                  ],
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
