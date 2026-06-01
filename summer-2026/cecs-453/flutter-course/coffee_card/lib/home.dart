import 'package:flutter/material.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Coffee Card', style: TextStyle(color: Colors.white)),
        backgroundColor: Colors.brown,
        centerTitle: true,
      ),
      body: Center(child: Text('Hello, World!')),
    );
  }
}
