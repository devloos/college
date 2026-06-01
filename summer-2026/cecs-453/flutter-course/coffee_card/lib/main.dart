import 'package:flutter/material.dart';
import 'package:coffee_card/home.dart';

void main() {
  runApp(const MaterialApp(home: Home()));
}

class Sandbox extends StatelessWidget {
  const Sandbox({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sandbox'),
        backgroundColor: Colors.grey,
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Container(width: 100, height: 100, color: Colors.red),
          Container(width: 100, height: 100, color: Colors.blue),
          Row(
            children: [
              Container(width: 100, height: 100, color: Colors.green),
              Container(width: 100, height: 100, color: Colors.yellow),
            ],
          ),
        ],
      ),
    );
  }
}
